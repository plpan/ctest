### herd
测试linux惊群效应：http://simohayha.iteye.com/blog/561424

- 可以多进程同时listen统一端口号，并且当请求到达时，只会有一个进程处理该请求
- linux已修复这个问题，故不会复现
