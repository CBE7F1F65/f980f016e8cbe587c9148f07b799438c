function Process:Render()
	
	export:ClientSetMatrix(self.worldx, self.worldy, self.worldz);
	
	if self.state == STATE_INIT then
		return self:RenderInitState();
	end
	
	hgeFont.printf(font,16,16,0,hge.Timer_GetFPS(35));
	if time > 0 and mp.state == STATE_TITLE then
		sel:Render();
		hgeSprite.RenderEx(spim.sprites.titles.sptitle, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y - 96, 0, 2.5)
	end
	
end

function Process:RenderInitState()
	if self.texInit ~= NULL then
		local quad=hge.struct.hgeQuad();
		quad.blend = BLEND_DEFAULT;
		quad.tex = self.texInit;
		local _col = M_FFFFFFFF;
		for i=1, 4 do
			quad.v[i].col = _col;
		end
		quad.v[1].tx = 0;	quad.v[1].ty = 0;
		quad.v[2].tx = 1;	quad.v[2].ty = 0;
		quad.v[3].tx = 1;	quad.v[3].ty = 1;
		quad.v[4].tx = 0;	quad.v[4].ty = 1;
		quad.v[1].x = M_CLIENT_LEFT;	quad.v[1].y = M_CLIENT_TOP;	quad.v[1].z = 0;
		quad.v[2].x = M_CLIENT_RIGHT;	quad.v[2].y = M_CLIENT_TOP;	quad.v[2].z = 0;
		quad.v[3].x = M_CLIENT_RIGHT;	quad.v[3].y = M_CLIENT_BOTTOM;	quad.v[3].z = 0;
		quad.v[4].x = M_CLIENT_LEFT;	quad.v[4].y = M_CLIENT_BOTTOM;	quad.v[4].z = 0;
		hge.Gfx_RenderQuad(quad);
	end

	return PGO;

end