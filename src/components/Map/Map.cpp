//
// Created by Jedrzej Lewandowski on 16/01/2020.
//

#include "Map.h"
#include <fstream>
#include <utility>

Map::Map(std::string textureId, int scale, int tileSize) {
  this->textureId = std::move(textureId);
  this->scale = scale;
  this->tileSize = tileSize;
}

void Map::LoadMap(const std::string& filePath, int mapSizeX, int mapSizeY) {
  std::fstream mapFile;
  mapFile.open(filePath);

  for (int y = 0; y < mapSizeY; y++) {
    for (int x = 0; x < mapSizeX; x++) {
      char ch;
      mapFile.get(ch);
      int sourceRectY = atoi(&ch) * tileSize;
      mapFile.get(ch);
      int sourceRectX = atoi(&ch) * tileSize;
      AddTile(sourceRectX, sourceRectY, x * (scale * tileSize),
              y * (scale * tileSize));
      mapFile.ignore();
    }
  }
  mapFile.close();
}

void Map::AddTile(int sourceRectX, int sourceRectY, int x, int y) {
}
