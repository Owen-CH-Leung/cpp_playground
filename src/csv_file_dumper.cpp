#include "csv_file_dumper.h"
#include <fstream>
#include <iostream>

void CSVFileDumper::clear() {
    columns.clear();
    filename.clear();
    rows.clear();
}

void CSVFileDumper::finish() const {
    if (filename.empty()) {
        throw std::runtime_error("Filenames are not set");
    }

    if (columns.empty()) {
        throw std::runtime_error("Columns are not set");
    }

    std::string content = columns + "\n" + rows;
    for (const auto& file : filename) {
        std::ofstream filestream(file);
        if (filestream) {
            filestream << content;
        } else {
            std::cerr << "Failed to open file " << file << std::endl;
        }
    }
}