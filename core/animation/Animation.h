#ifndef ANIMATION_H
#define ANIMATION_H

#include "../allegro/Allegro.h"
#include "../physics/Vector2D.h"

class Animation
{
	public:
		Animation();
		~Animation();

		void load(const char* path, int num_frames, int frame_delay = 0, bool loop = true);
		void load(ALLEGRO_BITMAP* bmp, int num_frames, int frame_delay = 0, bool loop = true);
		void update();
		void draw(Vector2D pos, double angle, bool flipped);
		void unload();

		int getCurrentFrameWidth();
		int getCurrentFrameHeight();
		void setCurrentFrameHeight();
		void setCurrentFrameWidth();

		bool hasPlayed();
		void reset();

	private:
		ALLEGRO_BITMAP *sprite_sheet;
		ALLEGRO_BITMAP *current_frame_bitmap;
		int num_frames;
		int frame_width;
		int frame_height;
		int frame_delay;
		bool loop;
		bool finished;
		int current_frame;
		int current_frame_delay;
};

#endif // ANIMATION_H
