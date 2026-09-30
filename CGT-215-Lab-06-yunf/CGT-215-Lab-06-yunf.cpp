#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int main() {
	string background = "images1/backgrounds/winter.png";
	string foreground = "images1/characters/yoda.png";
	//it tells where the images are at
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	// these are what load the images
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	// The lines above actually create the images

	Vector2u sz = backgroundImage.getSize();
	// according to the slides, the line above returns an instance of Vector2u

	Color greenColor = foregroundImage.getPixel(0, 0); 
	//the pixel of 0,0 from yoda's image is Green. Therefore, we assign that the pixel of 0, 0 is greenColor.
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {
			//the top line is for the row loop and the second line is for the coloum  loop where the y and x axis adds up by one w looping
			Color c = foregroundImage.getPixel(x, y); 
			// this color c means current pixel on the foregroundImage
			if
				(c == greenColor) //it checks whether if the current pixel they are on is the color green of 0, 0 Pixel from Yoda's image 
			{
				foregroundImage.setPixel(x, y, backgroundImage.getPixel(x, y));
				//we set pixels from the Background image(get pixel) on foreground Image, which is a photo of Yoda
			}
		}//In conclusion, it replaces the image of Yoda's background to the winter image if the pixel of Yoda's image is green.
	}
	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}