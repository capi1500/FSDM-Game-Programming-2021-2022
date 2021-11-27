#pragma once

template<class T>
class Listener{
	public:
		virtual void onNotify(const T&) = 0;
};


