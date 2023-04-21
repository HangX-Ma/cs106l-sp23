#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem> // make input easier
#include <vector>

typedef struct {
    std::string college;
    int year;
} st_status_t;

typedef std::map<std::string, st_status_t> map_t;

map_t
createMap(std::string filename) {
    map_t csMap;
    st_status_t studentStatus;
    std::vector<std::string> propertyList;

    /* Read the .csv file and store the information */
    std::string line;
    std::string property;
    std::ifstream fp(filename);
    if (!fp.is_open()) {
        std::perror("Open file failed. ErrMsg: ");
    }

    while (!fp.eof()) {
        std::getline(fp, line);
        std::istringstream strLine(line);

        for (int i = 0; i < 3; ++i) {
            getline(strLine, property, ',');
            propertyList.push_back(property);
        }

        if (propertyList.size() != (size_t) 3) {
            printf("[%s] at %d: Get incompatible property number.\n", __func__, __LINE__);
            return map_t();
        }

        studentStatus.college = propertyList.at(1);
        studentStatus.year = std::atoi(((propertyList.at(2)).c_str()));
        csMap.insert(map_t::value_type(propertyList.at(0), studentStatus));
        propertyList.clear();
    }
    fp.close();

    return csMap; 
}

void
printMap(map_t csMap) {
    size_t mapSize = csMap.size();
    if (mapSize == 0) {
        return;
    }

    std::string stanford = "Stanford University";
    for (auto iter = csMap.begin(); iter != csMap.end(); ++iter) {
        const auto& [st, status] = *iter;
        printf("Professor [%s] is [%sStanford] alum\n", 
                st.c_str(), 
                status.college.compare(stanford) == 0 ? "not " : "");
    }
}

int
main(int argc, char* argv[]) {
    // filename parser
    auto pwd = std::filesystem::current_path();
    if (argc != 2 || argv[1] == NULL) {
        std::cout << "Usage:\n\t./readcsv [filename]\t The file needs " 
            "to located at the same directory with your program." << std::endl;
        exit(1);
    }

    std::string inputFile = argv[1];
    bool checkFile = false;

    for (const auto& entry : std::filesystem::directory_iterator(pwd)) {
        std::string filename = entry.path().filename().string();
        std::cout << filename << std::endl;
        if (filename.compare(inputFile) == 0) {
            checkFile = true;
            break;
        }
    }

    if (!checkFile) {
        std::cout << "Your input file " << inputFile << " doesn't exist." << std::endl; 
        exit(1);
    }

    map_t csMap = createMap(inputFile);
    printMap(csMap);

    return 0;
}