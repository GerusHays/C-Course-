#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <string>
#include <map>
#include <vector>

/*
  ItemTracker

  This small utility class handles:
   - Loading an input text file containing one item per line
   - Counting frequency of each item using a std::map
   - Writing a backup file (frequency.dat)
   - Looking up individual item counts (with a forgiving, case-insensitive search)
   - Printing all counts

  I’m keeping the public interface simple and readable.
*/

class ItemTracker {
public:
    // Build empty tracker
    ItemTracker();

    // Load items from a text file (one item per line). Returns true on success.
    bool LoadFromFile(const std::string& inputPath);

    // Write the entire frequency table to a backup file (frequency.dat).
    // Returns true on success.
    bool WriteBackupFile(const std::string& outputPath) const;

    // Return the frequency of a requested item. If no exact match, try case-insensitive.
    // If not found, returns 0.
    int CountOf(const std::string& query) const;

    // Return a snapshot (copy) of the whole frequency table.
    std::map<std::string, int> AllCounts() const;

    // Print "Item count" lines (exact format used for frequency.dat).
    void PrintAll() const;

    // Print a histogram where each "*" equals one instance of that item.
    void PrintHistogram(char symbol = '*') const;

private:
    // Internal: normalize a string to lowercase (for tolerant lookups).
    static std::string ToLower(std::string s);

    // Internal: try to resolve a case-insensitive match and return the real key if found.
    // If not found, returns empty string.
    std::string ResolveKeyInsensitive(const std::string& query) const;

    // The main data structure: item → frequency
    std::map<std::string, int> freq_;
};

#endif 
