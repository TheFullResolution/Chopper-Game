//
// Created by Jedrzej Lewandowski on 16/01/2020.
//

#include "Map.h"
#include <fstream>
#include <iostream>

Map::Map(SDL_Texture* texture, const types::Map& mapConfig) {
  Map::scale = mapConfig.scale;
  Map::tileSize = mapConfig.tile_size;
  Map::texture = texture;
  Map::dimensions.x = scale * tileSize * mapConfig.map_size_x;
  Map::dimensions.y = scale * tileSize * mapConfig.map_size_y;

  std::fstream mapFile;
  mapFile.open(mapConfig.map_layout_file);

  for (int y = 0; y < mapConfig.map_size_y; y++) {
    for (int x = 0; x < mapConfig.map_size_x; x++) {
      char ch;
      mapFile.get(ch);
      int sourceRectY = atoi(&ch) * tileSize;
      mapFile.get(ch);
      int sourceRectX = atoi(&ch) * tileSize;
      int xpos{x * (scale * tileSize)};
      int ypos{y * (scale * tileSize)};

      AddTile(sourceRectX, sourceRectY, xpos, ypos);
      mapFile.ignore();
    }
  }
  mapFile.close();
}

void Map::AddTile(int sourceRectX, int sourceRectY, int x, int y) {
  tiles.emplace_back(new Tile(sourceRectX, sourceRectY, x, y, tileSize, scale));
}

void Map::Update(types::vector<float>& cameraPosition) {
  for (auto& tile : tiles) {
    tile->Update(cameraPosition);
  }
}

void Map::Render(SDL_Renderer* sdl_renderer) {
  for (auto& tile : tiles) {
    tile->Render(sdl_renderer, texture);
  }
}
const types::vector<float>& Map::getDimensions() const { return dimensions; }
