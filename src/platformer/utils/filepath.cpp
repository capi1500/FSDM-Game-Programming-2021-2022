#include "filepath.hpp"

bool Filepath::isFile() const{
	return fs::is_regular_file(path);
}

bool Filepath::isDirectory() const{
	return fs::is_directory(path);
}

Filepath::Filepath(const std::string& path) : path(path){}

Filepath::Filepath(const char* path) : path(path){}

void Filepath::execute(const std::function<void(const fs::path&)>& f, bool recursive){
	if(!path.empty()){
		if(isDirectory()){
			if(recursive){
				for(auto& p : fs::recursive_directory_iterator(path)){
					if(fs::is_regular_file(p.path()))
						f(p.path());
				}
			}
			else{
				for(auto& p : fs::directory_iterator(path)){
					if(fs::is_regular_file(p.path()))
						f(p.path());
				}
			}
		}
		if(isFile())
			f(path);
	}
}
