#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include "../models/Restaurant.h"

class RestaurantManager {
private:
    static RestaurantManager* instance;
    vector<Restaurant*> restaurants;

    RestaurantManager() {
        // Singleton: private constructor
    }

public:
    static RestaurantManager* getInstance() {
        if (instance == nullptr) {
            instance = new RestaurantManager();
        }
        return instance;
    } 
    
    void addRestaurant(Restaurant* restaurant) {
        restaurants.push_back(restaurant);
    }

    vector<Restaurant*> getByLocation(string &loc)  {
        vector<Restaurant*> result;
        transform(loc.begin(), loc.end(), loc.begin(), ::tolower);
        for (auto r : restaurants) {
            string rl = r->getLocation();
            transform(rl.begin(), rl.end(), rl.begin(), ::tolower);
            if (rl == loc) {
                result.push_back(r);
            }
        }
        return result;
    }

};

RestaurantManager* RestaurantManager::instance = nullptr;
#endif