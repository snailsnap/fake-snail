#include <iostream>
#include <fstream>
#include <string>
#include <random>

#include <QImage>
#include <QPainter>

int main(int argc, char *argv[])
{
	int inputImageCout = 10;
	int snailsPerInputImage = 5;
	std::ofstream metaFile("data/meta_file.csv");
	std::string baseName = "ZMB_Mol_";

	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(0, 255);

	metaFile << "Image,Color,Rotation,Ratio,OriginalImage,InventarNr,Class,Family,Genus,Species,Scientific Name,Fundort,Datum,Gebiet,Provinz,Land,Teilkontinent,Kontinent" << std::endl;
	for (auto i = (size_t)0; i < inputImageCout; i++) {
		for (auto j = (size_t)0; j < snailsPerInputImage; j++) {
			std::string imageName = baseName + std::to_string(i) + "_" + std::to_string(j) + ".png";
			std::string originalImageName = baseName + std::to_string(i) +  ".jpg";
			int r = uniform_dist(e1);
			int g = uniform_dist(e1);
			int b = uniform_dist(e1);

			metaFile << imageName << ",";
			metaFile << "#" << std::hex << (r<=0xf?"0":"") << r << (g <= 0xf ? "0" : "") << g << (b <= 0xf ? "0" : "") << b << std::dec << ",";
			metaFile << "0.0" << ",";
			metaFile << "1.0" << ",";
			metaFile << originalImageName << ",";
			metaFile << baseName << i << ",";
			metaFile << "Gastropoda,";
			metaFile << "Pleurodontidae,";
			metaFile << "Papuina,";
			metaFile << "migratoria,";
			metaFile << "Papuina migratoria,";
			metaFile << "Polynesia,";
			metaFile << "25.12.04,";
			metaFile << "Polynesia Area,";
			metaFile << "Bismarck Archipelago,";
			metaFile << "Solomon Islands,";
			metaFile << "Melanesia,";
			metaFile << "Oceania";
			metaFile << std::endl;

			QImage image(500, 500, QImage::Format_ARGB32);
			image.fill(QColor(0, 0, 0, 0));
			QPainter painter(&image);
			painter.setBrush(QBrush(QColor(r, g, b)));
			painter.drawEllipse(0, 0, 500, 500);

			image.save(("data/" + imageName).c_str());

		}
	}

}
