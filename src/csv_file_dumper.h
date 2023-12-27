#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class CSVFileDumper {
private:
    std::string columns;
    std::vector<std::string> filename;
    std::string rows;
    size_t n_cols;
public:
    CSVFileDumper() = default;
    ~CSVFileDumper() = default;
    CSVFileDumper(const CSVFileDumper& other) = default;
    CSVFileDumper& operator=(const CSVFileDumper& other) = default;

    void clear();
    void finish() const;

    template<typename... Cols>
    CSVFileDumper& setColumns(Cols... cols) {
        std::stringstream ss;
        ((ss << cols << ","), ...);
        std::string columns_str = ss.str();
        if (!columns_str.empty()) {
            columns_str.pop_back();
        }
        columns = std::move(columns_str);
        n_cols = std::count(columns.begin(), columns.end(), ',') + 1;
        return *this;
    }

    template<typename... Rows>
    CSVFileDumper& addRows(Rows... rows) {
        if (columns.empty()) {
            throw std::runtime_error("Columns are not set");
        }

        size_t n_rows = sizeof...(rows);
        if (n_rows != n_cols) {
            throw std::runtime_error("Number of rows does not match number of columns");
        }

        std::stringstream temp;
        ((temp << rows << ","), ...);
        std::string row_str = temp.str();
        if (!row_str.empty()) {
            row_str.pop_back();
        }

        this->rows.append(row_str).append("\n");
        return *this;
    }

    template<typename... Filename>
    CSVFileDumper& setFilename(Filename... filename) {
        this->filename.clear();
        ((this->filename.push_back(filename)), ...);
        return *this;
    }
};
