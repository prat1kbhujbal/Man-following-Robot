# Man-following-Robot

Robot locate and follow an human target moving in a environment. Whenever the person is detected in front, the robot will follow the person in that particular direction.

In this example first it moves to Table-1 in the gazebo world (i.e. Machinery lab in this examlpe) and then randomly walks anywhere for 7 meters.

## To launch world and nodes execute:
```
roslaunch my_robot world.launch
```
```
roslaunch drive_man man_chaser.launch
````

### To configure man's movements (option)
There are three basic function in **class** - 

* `moveforward(meters)` : To move forward in meters specified
* `turnleft(degrees)` : To turn man left in degrees
* `turnright(degrees)` : To turn man left in degrees

You can choose from above functions in class to move man around gazebo world

## Output
