Export	=	{
					}

function Export:ClientSet2DMode(self, x, y, z)
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

function Export:new(t)
    local t = t or {};
    self.__index = self;
    setmetatable( t, self );
    return t;
end

export = Export:new();