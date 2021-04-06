#pragma once 

namespace bounc { namespace graphics {
	
	class Window {
		private: 
			const char *m_Name;
			int m_Width, m_Height; 
			bool m_Closed; 

		private: 
			bool init();

		public: 
			Window(const char *name, int width, int height);
			~Window();

			void update() const; 
			bool closed() const;

		};

}}