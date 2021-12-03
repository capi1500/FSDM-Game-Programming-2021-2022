#pragma once

template<class T>
class Listener{
	public:
		virtual void onNotify(const T&) = 0;
		
		virtual ~Listener() = default;
};
