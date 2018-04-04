#include "Animation.h"
#include <iostream>

using namespace std;

Animation::Animation()
{
	//ctor
}

Animation::~Animation()
{
	//dtor
}
void Animation::load(ALLEGRO_BITMAP *bmp, int num_frames, int frame_delay, bool loop)
{
	this->num_frames = num_frames;
	this->frame_delay = frame_delay;
	this->loop = loop;
	finished = false;

	current_frame = 0;
	current_frame_delay = 0;
    sprite_sheet = bmp;

	if(sprite_sheet == NULL) cout << "Deu ruim na animation" << endl;
	frame_width = (al_get_bitmap_width(sprite_sheet) / num_frames);
	frame_height = al_get_bitmap_height(sprite_sheet);

	al_convert_mask_to_alpha(sprite_sheet,
                           al_map_rgb(255,0,255));

	current_frame_bitmap = al_create_bitmap(frame_width, frame_height);
}
void Animation::load(const char* path, int num_frames, int frame_delay, bool loop)
{
	this->num_frames = num_frames;
	this->frame_delay = frame_delay;
	this->loop = loop;
	finished = false;

	current_frame = 0;
	current_frame_delay = 0;

	sprite_sheet = al_load_bitmap(path);

	if(sprite_sheet == NULL) cout << "Deu ruim na animation" << endl;
	frame_width = (al_get_bitmap_width(sprite_sheet) / num_frames);
	frame_height = al_get_bitmap_height(sprite_sheet);

	al_convert_mask_to_alpha(sprite_sheet,
                           al_map_rgb(255,0,255));

	current_frame_bitmap = al_create_bitmap(frame_width, frame_height);
}

void Animation::update()
{
	if (loop || !finished)
	{
		current_frame_delay++;

		if (current_frame_delay >= frame_delay)
		{
			current_frame_delay = 0;
			current_frame++;
			if (current_frame >= num_frames)
			{
				current_frame = 0;
				finished = true;
			}
		}
	}

	if (finished && !loop)
	{
		current_frame = num_frames - 1;
	}
}

void Animation::draw(Vector2D pos, double angle, bool flipped)
{
	al_set_target_bitmap(current_frame_bitmap);

	int source_x = current_frame * frame_width;
	int source_y = 0;
	int dest_x = 0;
	int dest_y = 0;
	int flags = 0;

    if(flipped)
        flags = ALLEGRO_FLIP_HORIZONTAL;

	al_clear_to_color(al_map_rgba(0, 0, 0, 0));
	al_draw_bitmap_region(sprite_sheet, source_x, source_y, frame_width,frame_height, dest_x, dest_y, flags);
    //al_draw_tinted_bitmap_region(sprite_sheet, al_map_rgb(255,0,255),source_x, source_y, frame_width, frame_height, dest_x, dest_y, flags);
	al_set_target_backbuffer(Allegro::display);

	int pivot_x = al_get_bitmap_width(current_frame_bitmap) / 2;
	int pivot_y = al_get_bitmap_height(current_frame_bitmap) / 2;
	dest_x = pos.getX();
	dest_y = pos.getY();

	al_draw_rotated_bitmap(current_frame_bitmap, pivot_x, pivot_y,
                         dest_x, dest_y, (angle*M_PI/180), 0);
}

void Animation::unload()
{
	al_destroy_bitmap (current_frame_bitmap);
	al_destroy_bitmap (sprite_sheet);
}

int Animation::getCurrentFrameWidth()
{
	return frame_width;
}

int Animation::getCurrentFrameHeight()
{
	return frame_height;
}

bool Animation::hasPlayed()
{
	return finished;
}

void Animation::reset()
{
	finished = false;
	current_frame = 0;
}
