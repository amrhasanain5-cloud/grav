#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <sstream>
#include <functional>

namespace fs = std::filesystem;

int main(int argc, char** argv) {

    if (argc == 2) {
        std::string command = argv[1];
        if (command == "init") {
            fs::create_directory(".grav");
            fs::create_directories(".grav/.versions");
            fs::create_directories(".grav/.src");
            std::ofstream head_file(fs::path(".grav") / "HEAD.txt");
            std::ofstream config_file(fs::path(".grav") / ".cfg");
            std::ofstream log_file(fs::path(".grav") / ".log");
            

            std::cout << "\033[32mSuccessfully Initialized grav repository.\033[0m\n";
        }
    }
    else if (command == "-v" || command == "-version" || command == "--v") {
        std::cout << "Grav 0.1.0\033\n";
    }

    if (argc == 3) {
        std::string command = argv[1];
        fs::path filename = argv[2];
        if (command == "add") {
            if (!fs::exists(".grav") || !fs::is_directory(".grav")) {
                std::cout << "Not a grav repository\n";
            return 1;
            }
            fs::path filepath = filename;
            if (!fs::exists(filepath)) {
                std::cout << "No such file or directory `" 
                            << filename << "`\n";
                return 1;
            }
            fs::path codepath = fs::path(".grav") / ".src" / filepath.filename();
            fs::create_directories(codepath.parent_path());
            std::ifstream file(filepath);
            std::ofstream codefile(codepath);
            if (!file) {
                std::cout << "Cannot open source file\n";
                return 1;
            }
            if (!codefile) {
                std::cout << "Cannot create file: "
                        << codepath << "\n";
                return 1;
            }
            std::string line;
            while (std::getline(file, line)) {
                codefile << line << '\n';
            }
            std::cout << "Added: " << filename << "\n";
        }
    }
    if (argc == 5) {
        std::string command = argv[1];
        std::string version = argv[2];
        std::string mode = argv[3];
        std::string log = argv[4];
        if (command == "commit") {
            if (!fs::exists(".grav") || !fs::is_directory(".grav")) {
                std::cout << "Not a grav repository\n";
                return 0;
            }
            fs::path source = ".grav/.src";
            fs::path destination = fs::path(".grav/.versions") / version / "src";
            fs::create_directories(destination);
            fs::copy(
                source,
                destination,
                fs::copy_options::recursive |
                fs::copy_options::overwrite_existing
            );

            fs::remove_all(source);
            fs::create_directory(source);
            std::ofstream config_file(fs::path(".grav") / ".cfg");
            config_file << "name=`" << fs::current_path().filename().string() << "`\n"
            << "version=" << version;
            std::ofstream file(fs::path(".grav/HEAD.txt"), std::ios::out | std::ios::trunc);
            file << version;
            std::cout << "\033[32mCommitted version \033[0m";
            std::cout << ": " << version << std::endl;
            if (mode == "-log") {
                
                std::ofstream logging(
                    fs::path(".grav/.log"),
                    std::ios::out | std::ios::app
                );
                logging << version << " | " << log << "\n";
            }
        }
    }


    if (argc == 3) {
        std::string command = argv[1];
        std::string version = argv[2];
        if (command == "commit") {
            if (!fs::exists(".grav") || !fs::is_directory(".grav")) {
                std::cout << "Not a grav repository\n";
                return 0;
            }
            fs::path source = ".grav/.src";
            fs::path destination = fs::path(".grav/.versions") / version / "src";
            fs::create_directories(destination);
            fs::copy(
                source,
                destination,
                fs::copy_options::recursive |
                fs::copy_options::overwrite_existing
            );

            fs::remove_all(source);
            fs::create_directory(source);
            std::ofstream config_file(fs::path(".grav") / ".cfg");
            config_file << "name=`" << fs::current_path().filename().string() << "`\n"
            << "version=" << version;
            std::ofstream file(fs::path(".grav/HEAD.txt"), std::ios::out | std::ios::trunc);
            file << version;
            std::cout << "\033[32mCommitted version \033[0m";
            std::cout << ": " << version << std::endl;
        }
    }
    if (argc == 4) {
        std::string command = argv[1];
        fs::path repo = argv[2];
        fs::path destination = argv[3];
        if (command == "clone") {
            if (!fs::exists(repo)) {
                std::cout << "Repository does not exist\n";
                return 1;
            }
            if (!fs::is_directory(repo / ".grav")) {
                std::cout << "Not a grav repository\n";
                return 1;
            }
            std::ifstream file(repo / ".grav" / "HEAD.txt");
            if (!file) {
                std::cout << "Cannot read HEAD\n";
                return 1;
            }
            std::string version;
            file >> version;
            fs::path spath = repo / ".grav" / ".versions" / version / "src";
            if (!fs::exists(spath)) {
                std::cout << "Version does not exist\n";
                return 1;
            }        
            if (destination == "-c") {
                fs::copy(
                    spath,
                    fs::current_path(),
                    fs::copy_options::recursive |
                    fs::copy_options::overwrite_existing
                );
            }
            else {
            fs::create_directories(destination);
            fs::copy(
                spath,
                destination,
                fs::copy_options::recursive |
                fs::copy_options::overwrite_existing
                );
            }
        }
    }
    return 0;
}
