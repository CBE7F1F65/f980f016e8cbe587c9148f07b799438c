SE	=	{
			}

function SE:new(t)
    local t = t or {};
    self.__index = self;
    setmetatable( t, self );
    t:_Init();
    return t;
end

function SE:_Init()
	self.se = {};
	self.filename	=	{};
end

function SE:Release()
	for i in pairs(self.se) do
		if self.se[i] ~= nil and self.se[i] ~= NULL then
			hge.Effect_Free(self.se[i]);
		end
	end
	self:_Init();
end

se = SE:new();