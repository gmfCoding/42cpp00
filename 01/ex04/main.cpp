#include <fstream>
#include <string>

using std::string;
using std::ifstream;
using std::ofstream;

int main(int argc, char **argv)
{
	std::string filename;
	std::string line;
	std::string repstr;
	std::string newstr;
	
	ifstream infile;
  	ofstream outfile;

	if (argc != 4)
		return (0);
	filename = argv[1];
	repstr = argv[2];
	newstr = argv[3];
	
	infile.open (filename.c_str());
	if (!infile.is_open())
		return (0);

	outfile.open(filename.append(".replace").c_str());
	if (!outfile.is_open())
		return (0);
	
	while (getline(infile, line))
	{
		do	
		{
			// Foreach line occurance of repstr
			std::size_t index = line.find(repstr);
			if (index == string::npos)
			{
				outfile << line;
				break;
			}
			for(std::size_t i = 0; i < index; i++)
				outfile << line[i];
			outfile << newstr;
			line = &line[index + repstr.length()];
		} while (1);
		outfile << '\n';
	}
	infile.close();
	outfile.close();
}
