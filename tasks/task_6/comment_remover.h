#ifndef COMMENT_REMOVER_H
#define COMMENT_REMOVER_H

#include <string>
#include <fstream>

class CommentRemover {
public:
    static bool removeComments(const std::string& inputFilename);
    
private:
    static std::string generateOutputFilename(const std::string& inputFilename);
    static bool fileExists(const std::string& filename);
    static bool checkOverwrite(const std::string& filename);
    static void processFile(std::ifstream& input, std::ofstream& output);
    static char getNextChar(std::ifstream& input);
};

#endif // COMMENT_REMOVER_H