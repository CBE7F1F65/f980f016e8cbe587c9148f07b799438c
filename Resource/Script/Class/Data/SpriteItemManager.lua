SpriteItemManager	=	{
										}

function SpriteItemManager:new(t)
	local t = t or {};
	self.__index = self;
	setmetatable( t, self );
	t:_Init();
	return t;
end

function SpriteItemManager:_Init()
	self.tex	=	{};
	self.texx	=	{};
	self.texy	=	{};
	self.texw	=	{};
	self.texh	=	{};
	self.sprites = {};
end

function SpriteItemManager:Release()
	self:_Init();
end

spim = SpriteItemManager:new();