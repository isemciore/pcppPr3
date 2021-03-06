clear
clf
xValues = fread(fopen('obj/Debug/xValues50'),'double');
yValues = fread(fopen('obj/Debug/yValues20'),'double');
format = fread(fopen('obj/Debug/xValues50dataFormat'),'uint64');

mPoints = format(1);
nPoints = format(2);

figure(1)
hold on
for j = 0:nPoints-1
    plot(xValues((1:mPoints)+j*mPoints),yValues((1:mPoints)+j*mPoints));
end

for i = 0:mPoints-1
    plot(xValues((1:mPoints:end)+i),yValues((1:mPoints:end)+i));
end
axis([-11 6 -0.25 3.25])

if(false)
figure(2)
hold on
for j = 0:nPoints-1
    plot(xValues((1:mPoints)+j*mPoints),altyValues((1:mPoints)+j*mPoints));
end

for i = 0:mPoints-1
    plot(xValues((1:mPoints:end)+i),altyValues((1:mPoints:end)+i));
end
axis([-11 6 -0.25 3.25])
end