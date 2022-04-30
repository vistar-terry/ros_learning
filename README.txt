workspace目录结构
/build -- 编译空间(Build Space),用来存储工作空间编译过程中产生的缓存信息和中间文件.
/devel -- 开发空间(Development Space),用来放置编译生成的可执行文件.
/install -- 安装空间(Install Space),编译成功后,可以使用catkin_make install命令将可执行文件安装到这里,运行该空间中的环境变量脚本,即可在终端中运行这些可执行文件.安装空间不是必须的.
/src -- 源码空间(Source Space),存储所有ROS功能包的源码文件.