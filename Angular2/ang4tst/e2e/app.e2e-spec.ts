import { Ang4tstPage } from './app.po';

describe('ang4tst App', () => {
  let page: Ang4tstPage;

  beforeEach(() => {
    page = new Ang4tstPage();
  });

  it('should display message saying app works', () => {
    page.navigateTo();
    expect(page.getParagraphText()).toEqual('app works!');
  });
});
