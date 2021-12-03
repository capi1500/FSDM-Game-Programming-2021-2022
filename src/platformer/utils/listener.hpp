#pragma once

template<class T>
class Listener{
	public:
		virtual void onNotify(const T& event) = 0;
		
		virtual ~Listener() = default;
};
