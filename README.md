# TMX
Minimal TMX map parser

//Load the default map
mapTMXParser->loadMap("Starter", "Assets/maps/Starter.tmx");

//Cache map and other values
theMap = mapTMXParser->getMap("Starter");
tilesWidth = theMap->getWidth();
tilesHeight = theMap->getHeight();

void Game::renderMap()
{
	//These need to be cached so faster lookup!
	int columns = theMap->getTileSetForTileID(140)->getAttributeInt("columns");
	int tileSheetOffset = theMap->getTileSetForTileID(140)->getAttributeInt("firstgid");
	SDL_Rect src;
	src.w = 16;
	src.h = 16;

	SDL_Rect dest;
	dest.w = 16 * SCALE;
	dest.h = 16 * SCALE;

	for (int yt = 0; yt < tilesHeight; yt++)
	{
		for (int xt = 0; xt < tilesWidth; xt++)
		{
			int tileID = theMap->getLayer("Ground")->getData(xt, yt);

			//Don't draw empty spots!
			if (tileID == 0) {
				continue;
			}

			//Find which tilesheet it is

			//Calculate the offset
			int sheetID = tileID - tileSheetOffset;
			src.x = (sheetID % columns) * 16;
			src.y = (sheetID / columns) * 16;

			//Calcualate position of tile in screen space
			dest.x = xt * 16 * SCALE;
			dest.y = yt * 16 * SCALE;
      
			//Draw to screen
			AssetManager::get().DrawTexture("terrain", src, dest);
		}
	}
}
