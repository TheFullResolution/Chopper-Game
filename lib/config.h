//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Config data = nlohmann::json::parse(jsonString);

#pragma once

#include <nlohmann/json.hpp>

#ifndef NLOHMANN_OPT_HELPER
#define NLOHMANN_OPT_HELPER
namespace nlohmann {
    template <typename T>
    struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json & j, const std::shared_ptr<T> & opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static std::shared_ptr<T> from_json(const json & j) {
            if (j.is_null()) return std::unique_ptr<T>(); else return std::unique_ptr<T>(new T(j.get<T>()));
        }
    };
}
#endif

namespace config {
    using nlohmann::json;

    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<std::shared_ptr<T>>();
        }
        return std::shared_ptr<T>();
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json & j, std::string property) {
        return get_optional<T>(j, property.data());
    }

    struct Animation {
        int64_t speed;
        int64_t frame_width;
        int64_t frame_height;
    };

    struct Player {
        std::string file;
        int64_t width;
        int64_t height;
        int64_t x;
        int64_t y;
        int64_t scale;
        std::shared_ptr<Animation> animation;
    };

    struct Game {
        int64_t initial_window_width;
        int64_t initial_window_height;
        int64_t fps;
        std::string title;
    };

    struct Map {
        std::string map_image_file;
        std::string map_layout_file;
        int64_t scale;
        int64_t tile_size;
        int64_t map_size_x;
        int64_t map_size_y;
    };

    struct Config {
        std::string assets_path;
        std::string sprite_path;
        Game game;
        Map map;
        Player player;
        std::vector<Player> decorations;
    };
}

namespace nlohmann {
    void from_json(const json & j, config::Animation & x);
    void to_json(json & j, const config::Animation & x);

    void from_json(const json & j, config::Player & x);
    void to_json(json & j, const config::Player & x);

    void from_json(const json & j, config::Game & x);
    void to_json(json & j, const config::Game & x);

    void from_json(const json & j, config::Map & x);
    void to_json(json & j, const config::Map & x);

    void from_json(const json & j, config::Config & x);
    void to_json(json & j, const config::Config & x);

    inline void from_json(const json & j, config::Animation& x) {
        x.speed = j.at("speed").get<int64_t>();
        x.frame_width = j.at("frameWidth").get<int64_t>();
        x.frame_height = j.at("frameHeight").get<int64_t>();
    }

    inline void to_json(json & j, const config::Animation & x) {
        j = json::object();
        j["speed"] = x.speed;
        j["frameWidth"] = x.frame_width;
        j["frameHeight"] = x.frame_height;
    }

    inline void from_json(const json & j, config::Player& x) {
        x.file = j.at("file").get<std::string>();
        x.width = j.at("width").get<int64_t>();
        x.height = j.at("height").get<int64_t>();
        x.x = j.at("x").get<int64_t>();
        x.y = j.at("y").get<int64_t>();
        x.scale = j.at("scale").get<int64_t>();
        x.animation = config::get_optional<config::Animation>(j, "animation");
    }

    inline void to_json(json & j, const config::Player & x) {
        j = json::object();
        j["file"] = x.file;
        j["width"] = x.width;
        j["height"] = x.height;
        j["x"] = x.x;
        j["y"] = x.y;
        j["scale"] = x.scale;
        j["animation"] = x.animation;
    }

    inline void from_json(const json & j, config::Game& x) {
        x.initial_window_width = j.at("initialWindowWidth").get<int64_t>();
        x.initial_window_height = j.at("initialWindowHeight").get<int64_t>();
        x.fps = j.at("fps").get<int64_t>();
        x.title = j.at("title").get<std::string>();
    }

    inline void to_json(json & j, const config::Game & x) {
        j = json::object();
        j["initialWindowWidth"] = x.initial_window_width;
        j["initialWindowHeight"] = x.initial_window_height;
        j["fps"] = x.fps;
        j["title"] = x.title;
    }

    inline void from_json(const json & j, config::Map& x) {
        x.map_image_file = j.at("mapImageFile").get<std::string>();
        x.map_layout_file = j.at("mapLayoutFile").get<std::string>();
        x.scale = j.at("scale").get<int64_t>();
        x.tile_size = j.at("tileSize").get<int64_t>();
        x.map_size_x = j.at("mapSizeX").get<int64_t>();
        x.map_size_y = j.at("mapSizeY").get<int64_t>();
    }

    inline void to_json(json & j, const config::Map & x) {
        j = json::object();
        j["mapImageFile"] = x.map_image_file;
        j["mapLayoutFile"] = x.map_layout_file;
        j["scale"] = x.scale;
        j["tileSize"] = x.tile_size;
        j["mapSizeX"] = x.map_size_x;
        j["mapSizeY"] = x.map_size_y;
    }

    inline void from_json(const json & j, config::Config& x) {
        x.assets_path = j.at("assetsPath").get<std::string>();
        x.sprite_path = j.at("spritePath").get<std::string>();
        x.game = j.at("game").get<config::Game>();
        x.map = j.at("map").get<config::Map>();
        x.player = j.at("player").get<config::Player>();
        x.decorations = j.at("decorations").get<std::vector<config::Player>>();
    }

    inline void to_json(json & j, const config::Config & x) {
        j = json::object();
        j["assetsPath"] = x.assets_path;
        j["spritePath"] = x.sprite_path;
        j["game"] = x.game;
        j["map"] = x.map;
        j["player"] = x.player;
        j["decorations"] = x.decorations;
    }
}
