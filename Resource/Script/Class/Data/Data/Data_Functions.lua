function Data:_StringToDWORD(str, nums)
	if nums == nil or nums == 1 then
		return 0;
	end
	if nums == 4 then
		return 0, 0, 0, 0;
	end
end

function Data:_DWORDToString(d1, d2, d3, d4)
	return "RPY";
end

function Data:PushReplayHeader(name, difficult, stage, seed)
	self.rpyheader.sign = self:_StringToDWORD(M_REPLAYSIGN);
	self.rpyheader.magicnumber = M_REPLAYMAGICNUMBER;
	self.rpyheader.name[1], self.rpyheader.name[2], self.rpyheader.name[3], self.rpyheader.name[4] = self:_StringToDWORD(name, 4);
	self.rpyheader.diffstage = luastate.LShift(difficult, 16) + stage;
	self.rpyheader.seed = seed;
end

function Data:PushReplayData(data, index)
	if index == nil then
		index = time;
	end
	self.rpydata[index] = data;
end

function Data:GetReplayHeader()
	local name = self:_DWORDToString(self.rpyheader.name[1], self.rpyheader.name[2], self.rpyheader.name[3], self.rpyheader.name[4]);
	local difficult = luastate.RShift(self.rpyheader.diffstage, 16);
	local stage = luastate.And(self.rpyHeader.diffstage, 0xFFFF);
	return name, difficult, stage, self.rpyheader.seed;
end

function Data:GetReplayData(index)
	if index == nil then
		index = time;
	end
	return self.rpydata[index];
end

function Data:ClearReplayData()
	self.rpyheader = {};
	self.rpyheader.name = {};
	self.rpydata = {};
	self:FreeReplayContent();
end

function Data:SaveReplayContent()
	self.replaylength = self.headerlength + table.getn(self.rpydata) * 4;
	self.replaycontent = global.Malloc(self.replaylength);
	local nowoffset = 0;
	global.WriteMemory(self.replaycontent, nowoffset, self.rpyheader.sign);
	nowoffset	= nowoffset + 4;
	global.WriteMemory(self.replaycontent, nowoffset, self.rpyheader.magicnumber);
	nowoffset	= nowoffset + 4;
	global.WriteMemory(self.replaycontent, nowoffset, self.rpyheader.name[1]);
	nowoffset	= nowoffset + 4;
	global.WriteMemory(self.replaycontent, nowoffset, self.rpyheader.name[2]);
	nowoffset	= nowoffset + 4;
	global.WriteMemory(self.replaycontent, nowoffset, self.rpyheader.name[3]);
	nowoffset	= nowoffset + 4;
	global.WriteMemory(self.replaycontent, nowoffset, self.rpyheader.name[4]);
	nowoffset	= nowoffset + 4;
	global.WriteMemory(self.replaycontent, nowoffset, self.rpyheader.diffstage);
	nowoffset	= nowoffset + 4;
	global.WriteMemory(self.replaycontent, nowoffset, self.rpyheader.seed);
	nowoffset	= nowoffset + 4;
	for i, it in pairs(self.rpydata) do
		global.WriteMemory(self.replaycontent, self.headerlength + i * 4, it);
	end
	return self.replaycontent, self.replaylength;
end

function Data:LoadReplayContent(content, length)
	if length < self.headerlength then
		return false;
	end
	self:ClearReplayData();
	local nowoffset = 0;
	self.rpyheader.sign = global.ReadMemory(content, nowoffset);
	nowoffset = nowoffset + 4;
	if self.rpyheader.sign ~= self:_StringToDWORD(M_REPLAYSIGN) then
		return -1;
	end
	self.rpyheader.magicnumber = global.ReadMemory(content, nowoffset);
	nowoffset = nowoffset + 4;
	if self.rpyheader.magicnumber ~= M_REPLAYMAGICNUMBER then
		return -1;
	end
	self.rpyheader.name[1] = global.ReadMemory(content, nowoffset);
	nowoffset = nowoffset + 4;
	self.rpyheader.name[2] = global.ReadMemory(content, nowoffset);
	nowoffset = nowoffset + 4;
	self.rpyheader.name[3] = global.ReadMemory(content, nowoffset);
	nowoffset = nowoffset + 4;
	self.rpyheader.name[4] = global.ReadMemory(content, nowoffset);
	nowoffset = nowoffset + 4;
	self.rpyheader.diffstage = global.ReadMemory(content, nowoffset);
	nowoffset = nowoffset + 4;
	self.rpyheader.seed = global.ReadMemory(content, nowoffset);
	nowoffset = nowoffset + 4;
	
	if nowoffset >= length then
		return 0;
	end
	
	local index = 1;
	repeat
		self.rpydata[index] = global.ReadMemroy(content, nowoffset);
		index = index + 1;
		nowoffset = nowoffset + 4;
	until nowoffset >= length;
	return index - 1;
end

function Data:FreeReplayContent()
	if self.replaycontent ~= NULL then
		global.Free(self.replaycontent);
		self.replaycontent = NULL;
	end
	self.replaylength = 0;
end