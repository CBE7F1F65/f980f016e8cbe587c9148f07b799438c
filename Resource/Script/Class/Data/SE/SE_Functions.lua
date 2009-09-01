function SE:Init(tablefilename)
	if tablefilename == nil or tablefilename == "" then
		return;
	end
	local tabledata = {};
	local linecount;
	
	tabledata, linecount = tablefile:GetTableFileData(tablefilename, "nssffff");
	local seindex;
	for i=1, linecount do
		seindex = tabledata[1][i];
		self.filename[seindex] = tabledata[3][i];
		self.se[seindex] = hge.Effect_Load(self.filename[seindex]);
		luastate.SetConst(tabledata[2][i], self.se[seindex]);
	end
end