#pragma once

#include <experimental/filesystem>
#include <functional>

namespace fs = std::experimental::filesystem;

class Filepath{
	private:
		fs::path path;
	public:
		Filepath(const std::string& path);
		Filepath(const char* path);
		
		void execute(const std::function<void(const fs::path&)>& f, bool recursive = false);
		
		bool isFile() const;
		bool isDirectory() const;
};


