#include "SpikePlatform.h"
#include "../core/game/Game.h"

SpikePlatform::SpikePlatform(Vector2D position ,int spikeQty, int direction) :
                m_spikeQty(spikeQty), m_direction(direction)
{

    pos = position;
    init();
    m_collidable = true;
    type = SPIKE;
    //ctor
}

void SpikePlatform::init()
{


    m_spikePosition = new Vector2D[m_spikeQty];
    if((m_direction == UPWARD) || (m_direction == DOWNWARD))
        configHorizontal();
    if((m_direction == LEFTWARD) || (m_direction == RIGHTWARD))
        configVertical();






}

void SpikePlatform::configHorizontal()
{
     half_width = Vector2D( (m_spike.width() * m_spikeQty)/2 , 0 );
     half_height = Vector2D( 0 , (m_spike.height()/2) );

     double initialX = pos.getX() - half_width.getX();
     double posX;

     if(m_direction == UPWARD)
            m_spike.setDirection(UPWARD);
        else
            m_spike.setDirection(DOWNWARD);


    for(int i = 0; i < m_spikeQty; ++i)
    {
        posX = initialX + (i* m_spike.width()) + (m_spike.width()/2);
        m_spikePosition[i] = Vector2D(Vector2D(posX, pos.getY() ));

    }

}

void SpikePlatform::configVertical()
{

     half_width = Vector2D(  (m_spike.height())/2, 0 );
     half_height = Vector2D( 0,( m_spike.width() * m_spikeQty)/2 );



     double initialY = pos.getY() - half_height.getY();
     double posY;


     if(m_direction == LEFTWARD)
            m_spike.setDirection(LEFTWARD);
        else
            m_spike.setDirection(RIGHTWARD);


    for(int i = 0; i < m_spikeQty; ++i)
    {
        posY = initialY + (i*m_spike.width()) + (m_spike.width()/2);
        m_spikePosition[i] = Vector2D(Vector2D(pos.getX(), posY ));

    }
}

void SpikePlatform::draw()
{



    for(int i = 0; i < m_spikeQty; ++i)
        m_spike.draw(m_spikePosition[i]);
    if(Game::Instance()->debugMode)
    {
        al_draw_rectangle(pos.getX() - half_width.getX(), pos.getY() - half_height.getY(), pos.getX() + half_width.getX(), pos.getY() + half_height.getY(), al_map_rgb(255,0,0), 1.0);
        al_draw_filled_circle(pos.getX(), pos.getY(), 5, al_map_rgb(255,0,50));
    }
}

SpikePlatform::~SpikePlatform()
{
    //dtor
}
