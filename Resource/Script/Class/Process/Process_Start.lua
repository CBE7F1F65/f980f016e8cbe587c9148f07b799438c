function Process:ProcessStart()
	
	time = time + 1;

	local dt = hge.Timer_GetDelta();

	if hge.Input_GetDIKey(mp.keyLeft) then
		dx=dx-speed*dt;
	end
	if hge.Input_GetDIKey(mp.keyRight) then
		dx=dx+speed*dt;
	end
	if hge.Input_GetDIKey(mp.keyUp) then
		dy=dy-speed*dt;
	end
	if hge.Input_GetDIKey(mp.keyDown) then
		dy=dy+speed*dt;
	end

	dx = dx * friction;
	dy = dy * friction;
	x = x + dx;
	y = y + dy;
	local edge = 16
	local redge = M_CLIENT_RIGHT - edge;
	if x > redge then
		x = redge - (x-redge);
		dx = -dx;
		boom();
	end
	local ledge = edge;
	if x < ledge then
		x = ledge + (ledge-x);
		dx = -dx;
		boom();
	end
	local bedge = M_CLIENT_BOTTOM - edge;
	if y > bedge then
		y = bedge - (y-bedge);
		dy = -dy;
		boom();
	end
	local tedge = edge;
	if y < tedge then
		y = tedge + (tedge-y);
		dy = -dy;
		boom();
	end
	
	hgeES.MoveTo(eff, x, y);
	hgeES.Update(eff);
	for i=1,MAXEFF do
		local randx = hge.Random_Int(-50, 50);
		local randy = hge.Random_Int(-50, 50);
		hgeES.MoveTo(effs[i], x+randx, y+randy);
		hgeES.Update(effs[i]);
	end
	
	fps = hge.Timer_GetFPS(35);
	
	return PGO;
end