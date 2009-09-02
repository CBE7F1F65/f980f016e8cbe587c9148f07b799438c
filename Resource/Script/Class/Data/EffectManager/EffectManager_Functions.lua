function EffectManager:NewES(effindex, sptex)
	if sptex == nil then
		sptex = NULL;
	end
	return hgeES.NewES(self.filename[effindex], sptex);
end

function EffectManager:Init(tablefilename)
	if tablefilename == nil or tablefilename == "" then
		return;
	end
	local tabledata = {};
	local linecount;
	
	tabledata, linecount = tablefile:GetTableFileData(tablefilename, "nss");
	local effindex;
	for i=1, linecount do
		effindex = tabledata[1][i];
		luastate.SetConst(tabledata[2][i], effindex);
		self.filename[effindex] = tabledata[3][i];
	end
end