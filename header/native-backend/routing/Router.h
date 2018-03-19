//
// Created by albert on 3/13/18.
//

#ifndef NATIVE_BACKEND_ROUTER_H
#define NATIVE_BACKEND_ROUTER_H

#include <native-backend/utils/Singleton.h>
#include <functional>
#include <native-backend/server/HttpVerb.h>
#include <native-backend/widgets/IWidget.h>
#include <unordered_map>
#include <boost/move/unique_ptr.hpp>
#include <boost/shared_ptr.hpp>

namespace nvb{
    /*!\brief Used to map functions to certain http requests.*/
    class Router : public Singleton<Router> {
    public:
        Router() = default;
        void addRoute(HttpVerb::Verb verb, std::string path, std::function<boost::shared_ptr<IWidget>(void)> builder);
        boost::shared_ptr<IWidget> evaluateRoute(HttpVerb::Verb verb, std::string path);
    private:
        /*!\brief Member for saving routes.
        Example usage: The path is '/user/index', the http verb is get
         routes_map_.find('/user/index').find(HttpVerb::get) would return the registered function.*/
        std::unordered_map<std::string,
                std::unordered_map<HttpVerb::Verb, std::function<boost::shared_ptr<IWidget>(void)>>> routes_map_;
    };
}



#endif //NATIVE_BACKEND_ROUTER_H
