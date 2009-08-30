Data	=	{
				}

function Data:new(t)
    local t = t or {};
    self.__index = self;
    setmetatable( t, self );
    t:_Init();
    return t;
end

function Data:_Init()
end

function Data:Init(filename)
	self.filename = hge.Resource_MakePath(filename);
end

function Data:Release()
end

data = Data:new();