#include "ItemTracker.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cctype>

ItemTracker::ItemTracker() : freq_{} {}

bool ItemTracker::LoadFromFile(const std::string& inputPath) {
    std::ifstream in(inputPath);
    if (!in.is_open()) {
        std::cerr << "Error: Could not open input file: " << inputPath << std::endl;
        return false;
    }

    // Read one item per line; trim whitespace
    std::string line;
    while (std::getline(in, line)) {
        // quick trim: remove trailing \r or spaces
        while (!line.empty() && (line.back() == '\r' || line.back() == ' ' || line.back() == '\t')) {
            line.pop_back();
        }
        while (!line.empty() && (line.front() == ' ' || line.front() == '\t')) {
            line.erase(line.begin());
        }
        if (!line.empty()) {
            ++freq_[line]; 
        }
    }

    return true;
}

bool ItemTracker::WriteBackupFile(const std::string& outputPath) const {
    std::ofstream out(outputPath);
    if (!out.is_open()) {
        std::cerr << "Error: Could not open output file for backup: " << outputPath << std::endl;
        return false;
    }
    for (const auto& [item, count] : freq_) {
        out << item << " " << count << '\n';
    }
    return true;
}

int ItemTracker::CountOf(const std::string& query) const {
    // Try exact first (fast path)
    auto it = freq_.find(query);
    if (it != freq_.end()) return it->second;

    // Fall back to a forgiving (case-insensitive) search
    std::string resolved = ResolveKeyInsensitive(query);
    if (!resolved.empty()) {
        return freq_.at(resolved);
    }
    return 0;
}

std::map<std::string, int> ItemTracker::AllCounts() const {
    return freq_; // return by value (a copy)
}

void ItemTracker::PrintAll() const {
    for (const auto& [item, count] : freq_) {
        std::cout << item << " " << count << '\n';
    }
}

void ItemTracker::PrintHistogram(char symbol) const {
    for (const auto& [item, count] : freq_) {
        std::cout << item << " ";
        for (int i = 0; i < count; ++i) {
            std::cout << symbol;
        }
        std::cout << '\n';
    }
}

std::string ItemTracker::ToLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return s;
}

std::string ItemTracker::ResolveKeyInsensitive(const std::string& query) const {
    std::string q = ToLower(query);
    for (const auto& [item, _] : freq_) {
        if (ToLower(item) == q) {
            return item; // return the actual cased key
        }
    }
    return {};
}
