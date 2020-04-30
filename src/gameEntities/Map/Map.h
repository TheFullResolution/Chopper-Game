//
// Created by Jedrzej Lewandowski on 16/01/2020.
//

#ifndef CHOPPERGAME_MAP_H
#define CHOPPERGAME_MAP_H

#include <string>
#include <vector>
#include "../../components/Tile/Tile.h"

class Map {
 private:
  void AddTile(int sourceX, int sourceY, int x, int y);

  SDL_Texture* texture;
  std::vector<Tile*> tiles;
  int scale;
  int tileSize;
  types::vector<float> dimensions{};

 public:
  Map(SDL_Texture* texture, const types::Map& mapConfig);
  void Render(SDL_Renderer* sdl_renderer);
  void Update(types::vector<float>& cameraPosition);
  const types::vector<float>& getDimensions() const;
};

#endif  // CHOPPERGAME_MAP_H
