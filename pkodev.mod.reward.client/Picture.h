#pragma once

namespace pkodev
{
	namespace pointer
	{

		// CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
		typedef void(__thiscall* CGuiPic__CGuiPic__Ptr)(void*, void*, unsigned int);

		// bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
		typedef bool(__thiscall* CGuiPic__LoadImage__Ptr)(void*, const char*, int, int, int, int, int, float, float);

		// inline void CGuiPic::Render( int x, int y )
		typedef void(__thiscall* CGuiPic__Render__Ptr)(void*, int, int, int);
	}

	namespace gui
	{
		// Wrapper for GUI picture functions
		class Picture
		{
			public:

				// Constructor
				Picture();

				// Copy constructor
				Picture(const Picture&) = delete;

				// Move constructor
				Picture(Picture&&) = delete;

				// Destructor
				~Picture();

				// Copy assigment operator
				Picture& operator=(const Picture&) = delete;

				// Move assigment operator
				Picture& operator=(Picture&) = delete;

				// Load picture from a file
				bool load(const char* path, int w = 32, int h = 32, int tx = 0, int ty = 0);

				// Draw picture
				void render(int x, int y);

			private:

				// Memory block for CGuiPic data
				char m_data[0x14];
		};
	}
}

