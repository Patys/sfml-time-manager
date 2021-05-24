# sfml-time-manager
Manager to run function after specific time.

# Installation

`git submodule add https://github.com/patys/sfml-time-manager Time`

It will create submodule in your git project. Now you can just

```
#include "Time/Time.hpp"
```

# Usage
```
Time gameTime;

gameTime.update([&](){
  // your code here will be running every 100 ms by default
});

```
## Available functions

update => running every 100 ms by default
```
void update(std::function<void ()> func)
```

setSpeedFactor => make game X times faster, useful when making e.g. x2, x4 speed up
```
void setSpeedFactor(float factor)
```

pause => stop timer
```
void pause()
```

resume => start timer
```
void resume()
```

togglePause => start or stop timer
```  
void togglePause()
```

getDelta => useful for rendering, it's deltaTime
```
sf::Time getDelta()
```

getGameDate => date in format DD.MM.YYYY
```
std::string getGameDate()
```
