#ifndef __SOUND_H__
#define __SOUND_H__

#include <string>
#include <SFML/Audio.hpp>

namespace df {
	class Sound {
	private:
		sf::Sound sound; //sfml dound
		sf::SoundBuffer sound_buffer; //sfml sound buffer associated
		std::string label; //text label to dientify sound

	public:
		Sound();
		~Sound();

		//load sound bugger from file
		int loadSound(std::string filename);

		void setLabel(std::string new_label);

		std::string getLabel() const;

		void play(bool loop = false);

		void stop();

		void pause();

		sf::Sound getSound() const;


	};
}
#endif
