#pragma once

class Scene;

class SceneEvent{
	private:
		int eventId;
		mutable Scene* scene;
	public:
		int getEventId() const{
			return eventId;
		}
		
		Scene* getScene() const;
		
		explicit SceneEvent(int eventId) : eventId(eventId){}
		virtual ~SceneEvent() = default;
		
		friend class Scene;
};
