#include "Picture.h"
#include "address.h"

namespace pkodev
{
	namespace gui
	{
		// CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
		pointer::CGuiPic__CGuiPic__Ptr CGuiPic__CGuiPic = (pointer::CGuiPic__CGuiPic__Ptr)(void*)(address::CGuiPic__CGuiPic);
		
		// bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
		pointer::CGuiPic__LoadImage__Ptr CGuiPic__LoadImage = (pointer::CGuiPic__LoadImage__Ptr)(void*)(address::CGuiPic__LoadImage);

		// inline void CGuiPic::Render( int x, int y )
		pointer::CGuiPic__Render__Ptr CGuiPic__Render = (pointer::CGuiPic__Render__Ptr)(void*)(address::CGuiPic__Render);


		// Constructor
		Picture::Picture()
		{
			// Call CGuiPic constructor
			CGuiPic__CGuiPic(reinterpret_cast<void*>(m_data), nullptr, 0);
		}

		// Destructor
		Picture::~Picture()
		{
			// Call CGuiPic destructor

		}

		// Load picture from a file
		bool Picture::load(const char* path, int w, int h, int tx, int ty)
		{
			return CGuiPic__LoadImage(reinterpret_cast<void*>(m_data), path, w, h, tx, ty, 0, 0, 0);
		}

		// Draw picture
		void Picture::render(int x, int y)
		{
			CGuiPic__Render(
				reinterpret_cast<void*>(pkodev::address::CGuiPic),
				x,
				y,
				(
					*reinterpret_cast<unsigned int*>(
						reinterpret_cast<unsigned int>(m_data)
						)
					+
					*reinterpret_cast<unsigned int*>(
						reinterpret_cast<unsigned int>(m_data) + 4
						)
					)
			);
		}
	}
}