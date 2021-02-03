
#include "Parser/Driver.hh"

int main(int argc, char *argv[]) {
    int result = 0;
    Driver driver;
    //for (size_t i = 1; i < argc; i++) {
    //    if (argv[i] == std::string("-a"))
    //        driver.trace_ast = true;
    //    else if (argv[i] == std::string("-s"))
    //        
    //}
    driver.trace_ast = true;
    if (!driver.parse(argv[1])) {
        std::cout << driver.result << std::endl;
        result = 1;
    }

    return result;
}