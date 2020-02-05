//
// Created by Jedrzej Lewandowski on 16/01/2020.
//

#ifndef CHOPPERGAME_MAP_H
#define CHOPPERGAME_MAP_H

#include <string>

class Map {
public:
  Map(std::string textureId, int scale, int tileSize);

  void LoadMap(const std::string& filePath, int mapSizeX, int MapSizeY);

  void AddTile(int sourceX, int sourceY, int x, int y);

private:
  std::string textureId;
  int scale;
  int tileSize;
};

#endif // CHOPPERGAME_MAP_H
