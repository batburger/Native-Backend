//
// Created by albert on 3/14/18.
//

#ifndef NATIVE_BACKEND_REQUESTINFOMRATION_H
#define NATIVE_BACKEND_REQUESTINFOMRATION_H

#include <regex>
#include <boost/shared_ptr.hpp>
#include <unordered_map>

namespace nvb{
    /*!\brief Class which parses and holds information about the request.*/
    class RequestInformation {
    private:
        RequestInformation(std::string &path_, std::unordered_map<std::string, std::string>& params_);

    public:
        static boost::shared_ptr<nvb::RequestInformation> create(std::string& requestString);

        const std::unordered_map<std::string, std::string> params;
        const std::string path;

    };
}


#endif //NATIVE_BACKEND_REQUESTINFOMRATION_H
