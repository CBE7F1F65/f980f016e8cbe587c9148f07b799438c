EffectManager	=	{
								}

function EffectManager:new(t)
    local t = t or {};
    self.__index = self;
    setmetatable( t, self );
    t:_Init();
    return t;
end

function EffectManager:_Init()
	self.filename	=	{};
end

function EffectManager:Release()
	self.filename = {};
end

effm = EffectManager:new();