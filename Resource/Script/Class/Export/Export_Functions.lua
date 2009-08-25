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