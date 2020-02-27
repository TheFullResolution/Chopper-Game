//  To parse this JSON data, first install
//
//      Boost     http://www.boost.org
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Config data = nlohmann::json::parse(jsonString);

#pragma once

#include <nlohmann/json.hpp>

namespace quicktype {
using nlohmann::json;

inline json get_untyped(const json &j, const char *property) {
  if (j.find(property) != j.end()) {
    return j.at(property).get<json>();
  }
  return json();
}

inline json get_untyped(const json &j, std::string property) {
  return get_untyped(j, property.data());
}

struct Decoration {
  std::string file;
  int64_t width;
  int64_t height;
  int64_t x;
  int64_t y;
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
  Map map;
  std::vector<Decoration> decorations;
};
} // namespace quicktype

namespace nlohmann {
void from_json(const json &j, quicktype::Decoration &x);
void to_json(json &j, const quicktype::Decoration &x);

void from_json(const json &j, quicktype::Map &x);
void to_json(json &j, const quicktype::Map &x);

void from_json(const json &j, quicktype::Config &x);
void to_json(json &j, const quicktype::Config &x);

inline void from_json(const json &j, quicktype::Decoration &x) {
  x.file = j.at("file").get<std::string>();
  x.width = j.at("width").get<int64_t>();
  x.height = j.at("height").get<int64_t>();
  x.x = j.at("x").get<int64_t>();
  x.y = j.at("y").get<int64_t>();
}

inline void to_json(json &j, const quicktype::Decoration &x) {
  j = json::object();
  j["file"] = x.file;
  j["width"] = x.width;
  j["height"] = x.height;
  j["x"] = x.x;
  j["y"] = x.y;
}

inline void from_json(const json &j, quicktype::Map &x) {
  x.map_image_file = j.at("mapImageFile").get<std::string>();
  x.map_layout_file = j.at("mapLayoutFile").get<std::string>();
  x.scale = j.at("scale").get<int64_t>();
  x.tile_size = j.at("tileSize").get<int64_t>();
  x.map_size_x = j.at("mapSizeX").get<int64_t>();
  x.map_size_y = j.at("mapSizeY").get<int64_t>();
}

inline void to_json(json &j, const quicktype::Map &x) {
  j = json::object();
  j["mapImageFile"] = x.map_image_file;
  j["mapLayoutFile"] = x.map_layout_file;
  j["scale"] = x.scale;
  j["tileSize"] = x.tile_size;
  j["mapSizeX"] = x.map_size_x;
  j["mapSizeY"] = x.map_size_y;
}

inline void from_json(const json &j, quicktype::Config &x) {
  x.assets_path = j.at("assetsPath").get<std::string>();
  x.sprite_path = j.at("spritePath").get<std::string>();
  x.map = j.at("map").get<quicktype::Map>();
  x.decorations = j.at("decorations").get<std::vector<quicktype::Decoration>>();
}

inline void to_json(json &j, const quicktype::Config &x) {
  j = json::object();
  j["assetsPath"] = x.assets_path;
  j["spritePath"] = x.sprite_path;
  j["map"] = x.map;
  j["decorations"] = x.decorations;
}
} // namespace nlohmann
