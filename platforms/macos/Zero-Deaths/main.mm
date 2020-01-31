#include <string>
#import <Foundation/Foundation.h>
#include "Application/ApplicationFactory.hpp"

std::string resourcePath(void);

int main(int argc, const char* argv[]) {
	ApplicationFactory appFactory(resourcePath());
	Application app = appFactory.make();
	app.run();
	
	return 0;
}

std::string resourcePath(void) {
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	
	std::string rpath;
	NSBundle* bundle = [NSBundle mainBundle];
	
	if (bundle == nil) {
		#ifdef DEBUG
		NSLog(@"bundle is nil... thus no resources path can be found.");
		#endif
	} else {
		NSString* path = [bundle resourcePath];
		rpath = [path UTF8String] + std::string("/");
	}
	
	[pool drain];
	
	return rpath;
}

