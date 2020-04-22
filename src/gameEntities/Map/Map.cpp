//
// Created by Jedrzej Lewandowski on 16/01/2020.
//

#include "Map.h"
#include <fstream>
#include <iostream>

Map::Map(SDL_Texture *texture, const std::string &mapLayoutFile, int scale,
         int tileSize, int mapSizeX, int mapSizeY)
    : texture(texture), scale(scale), tileSize(tileSize) {

  LoadMap(mapLayoutFile, mapSizeX, mapSizeY);
}

void Map::LoadMap(const std::string &filePath, int mapSizeX, int mapSizeY) {
  std::fstream mapFile;
  mapFile.open(filePath);

  for (int y = 0; y < mapSizeY; y++) {
    for (int x = 0; x < mapSizeX; x++) {
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

void Map::Update(utils::vector &cameraPosition) {
  for (auto &tile : tiles) {
    tile->Update(cameraPosition);
  }
}

void Map::Render(SDL_Renderer *sdl_renderer) {
  for (auto &tile : tiles) {
    tile->Render(sdl_renderer, texture);
  }
}
