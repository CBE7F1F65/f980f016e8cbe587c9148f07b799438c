Texture	=	{
					}

function Texture:new(t)
    local t = t or {};
    self.__index = self;
    setmetatable( t, self );
    t:_Init();
    return t;
end

function Texture:_Init()
	self.tex = {};
	self.filename = {};
end

function Texture:Release()
	local ntex = table.getn(self.tex);
	for i=1, ntex do
		if self.tex[i] ~= nil and self.tex[i] ~= 0 then
			hge.Texture_Free(self.tex[i]);
			self.tex[i] = 0;
			self.filename[i] = "";
		end
	end
end

tex = Texture:new();