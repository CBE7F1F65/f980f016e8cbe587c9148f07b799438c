function Export:ClientSet2DMode(x, y, z)
	if x == nil then
		x = 400;
	end
	if y == nil then
		y = 300;
	end
	if z == nil then
		z = 300;
	end
	hge.System_Set2DMode(x, y, z);
end

function Export:GetPassword()
	local szPassword = hge.Ini_GetString(RESCONFIGS_RESOURCE, RESCONFIGN_PASSWORD, RESCONFIGDEFAULT_PASSWORD);
	local password = luastate.DWORDToInt(hge.Resource_GetCRC(szPassword));
	return password;
end

function Export:ClientSetMatrix(x, y, z)
	matWorld	= 	{
									{1, 0, 0, 0},
									{0, 1, 0, 0},
									{0, 0, 1, 0},
									{x, y, z, 1},
								}
	hge.Gfx_SetTransform(D3DTS_WORLD, matWorld);
	if hge.System_Is2DMode() then
		return;
	end
	
	matView	= 	{
								{1, 0, 0, 0},
								{0, -1, 0, 0},
								{0, 0, -1, 0},
								{-M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y, M_CLIENT_HEIGHT / 2, 1},
							}
	hge.Gfx_SetTransform(D3DTS_VIEW, matView);
	
	matProj	= 	{
								{M_CLIENT_HEIGHT / M_CLIENT_WIDTH, 0, 0, 0},
								{0, 1, 0, 0},
								{0, 0, 0, 1},
								{-0.5, 0.5, 0, -0.55},
							}
	hge.Gfx_SetTransform(D3DTS_PROJECTION, matProj);
end