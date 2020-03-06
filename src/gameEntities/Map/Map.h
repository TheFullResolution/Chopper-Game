//
// Created by Jedrzej Lewandowski on 16/01/2020.
//

#ifndef CHOPPERGAME_MAP_H
#define CHOPPERGAME_MAP_H

#include "../../components/Tile/Tile.h"
#include <string>
#include <vector>

class Map {
public:
  Map(const std::string& mapImageFile, const std::string& mapLayoutFile, int scale,
      int tileSize, int mapSizeX, int mapSizeY);
  void Render();

private:
  void AddTile(int sourceX, int sourceY, int x, int y);
  void LoadMap(const std::string &filePath, int mapSizeX, int MapSizeY);

  SDL_Texture *texture;
  std::vector<Tile *> tiles;
  int scale;
  int tileSize;
};

#endif // CHOPPERGAME_MAP_H
